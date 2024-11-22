//
//  SwiftUIViewProvider.swift
//  iOSSample
//
//  Created by Roman Do on 22.11.2024.
//  Copyright © 2024 Display.io. All rights reserved.
//

import SwiftUI
import UIKit

@objc class SwiftUIViewProvider: NSObject {
    @MainActor @objc static func createFeedViewController(placementId: String, adUnitType: String) -> UIViewController {
        let feedView = FeedView(placementId: placementId, adUnitType: adUnitType)
        return UIHostingController(rootView: feedView)
    }
}
