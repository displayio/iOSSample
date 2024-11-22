//
//  SwiftUIView.swift
//  iOSSample
//
//  Created by Roman Do on 22.11.2024.
//  Copyright © 2024 Display.io. All rights reserved.
//

import SwiftUI
import DIOSDK

struct FeedView: View {
    let placementId: String
    let adUnitType: String
    
    @State var items = Array(1...400).map { "Item \($0)" }
    @State var ads = Array<DIOAd?>(repeating: nil, count: 11)
    
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
        .onAppear {
            loadAds()
        }
        .onDisappear {
            for ad in ads {
                ad?.finish()
            }
        }
    }
    
    private func loadAds() {
        for i in 1..<11 {
            let placement = DIOController.sharedInstance().placement(withId: placementId)
            let adRequest = placement.newAdRequest()
            adRequest.requestAd {  ad in
                print("AD" + ad.description)
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
        let isInfeed = adUnitType.elementsEqual("IF")
        return AnyView(isInfeed ?
                       DIOAdViewRepresentable(adView: adView).frame(width: 300, height: 250) :
                        DIOAdViewRepresentable(adView: adView).frame(height: 800)
        )
    }
}

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
