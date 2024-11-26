//
//  FeedView.swift
//  DIOApp
//
//  Created by Roman Do on 25.11.2024.
//  Copyright © 2024 Display.io. All rights reserved.
//

import SwiftUI
import DIOSDK

@available(iOS 15.0, *)
struct FeedView: View {
    let placementId: String
    let adUnitType: String
    
    @State var items = Array(1...400).map { "Item \($0)" }
    @State var ads = Array<DIOAd?>(repeating: nil, count: 11)
    @State private var interscrollerHeight: CGFloat = 0.0
    @State private var interscrollerOffset: CGFloat = 0.0
    
    var body: some View {
        List(items, id: \.self) { item in
            if item.contains("Item") {
                Text(item)
                    .font(.headline)
                    .padding(30)
                    .listRowInsets(EdgeInsets())
                
            } else {
                HStack {
                    Spacer(minLength: 0)
                    getAdView(requestId: item)
                    Spacer(minLength: 0)
                }.listRowInsets(EdgeInsets())
            }
        }
        .listStyle(.grouped)
        .onDisappear() {
            for ad in ads {
                ad?.finish()
            }
        }
        .background(
            GeometryReader { geometry in
                Color.clear
                    .onAppear {
                        calculateOffset(listHeight: geometry.size.height)
                        loadAds()
                    }
                    .onChange(of: geometry.size) { newSize in
                        calculateOffset(listHeight: geometry.size.height)
                    }
            }
        )
    }
    
    private func loadAds() {
        for i in 1..<11 {
            let placement = DIOController.sharedInstance().placement(withId: placementId)
            if (adUnitType.elementsEqual("interscroller")) {
                (placement as! DIOInterscrollerPlacement).interscrollerSize = Int32(interscrollerHeight)
                (placement as! DIOInterscrollerPlacement).interscrollerOffset = Int32(interscrollerOffset)
            }
            let adRequest = placement.newAdRequest()
            adRequest.requestAd {  ad in
                ads[i] = ad
                items[i*10] = ad.requestId
            } noAdHandler: { error in
                print("No ads" + error.localizedDescription)
            }
        }
    }
    
    private func getAdView(requestId: String) -> some View {
        guard let adView = DIOController.sharedInstance().placement(withId: placementId).adRequest(byId: requestId).ad?.view() else {
            return AnyView(EmptyView())
        }
        let isInfeed = adUnitType.elementsEqual("infeed")
        return AnyView(isInfeed ?
                       DIOAdViewRepresentable(adView: adView).frame(width: 300, height: 250) :  //the size of Infeed is 300x250
                       DIOAdViewRepresentable(adView: adView).frame(height: interscrollerHeight) //calculate the height of list view
        )
    }
    
    private func calculateOffset(listHeight: CGFloat) {
        if let window = UIApplication.shared.connectedScenes
            .compactMap({ $0 as? UIWindowScene })
            .flatMap({ $0.windows })
            .first(where: { $0.isKeyWindow }) {
            
            let bottomBarHeight = window.safeAreaInsets.bottom
            interscrollerHeight = listHeight + bottomBarHeight
            interscrollerOffset = UIScreen.main.bounds.height - interscrollerHeight
        }
    }
}

@available(iOS 13.0, *)
struct DIOAdViewRepresentable: UIViewRepresentable {
    var adView: UIView
    
    func makeUIView(context: Context) -> UIView {
        
        let containerView = UIView()
        containerView.addSubview(adView)
        adView.translatesAutoresizingMaskIntoConstraints = false
        
        NSLayoutConstraint.activate([
            adView.topAnchor.constraint(equalTo: containerView.topAnchor),
            adView.bottomAnchor.constraint(equalTo: containerView.bottomAnchor),
            adView.leadingAnchor.constraint(equalTo: containerView.leadingAnchor),
            adView.trailingAnchor.constraint(equalTo: containerView.trailingAnchor)
        ])
        
        return containerView
    }
    
    func updateUIView(_ uiView: UIView, context: Context) {
    }
}

@available(iOS 15.0, *)
@objc class SwiftUIViewProvider: NSObject {
    @MainActor @objc static func createFeedViewController(placementId: String, adUnitType: String) -> UIViewController {
        let feedView = FeedView(placementId: placementId, adUnitType: adUnitType)
        let hostingController = UIHostingController(rootView: feedView)
        return hostingController
    }
}


@available(iOS 13.0, *)
class ClosableHostingController<Content: View>: UIHostingController<Content> {

}


