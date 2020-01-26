//
//  DIOFeedInterstitialHtml.h
//  DIOSDK
//
//  Created by Ariel Malka on 11/18/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import "DIOHtmlAd.h"
#import "DIOFeedInterstitialView.h"

NS_ASSUME_NONNULL_BEGIN

@interface DIOFeedInterstitialHtml : DIOHtmlAd <DIOFeedInterstitialViewDelegate>

@property (nonatomic) BOOL closed;
@property (nonatomic, weak) DIOFeedInterstitialView *containerView;

@end

NS_ASSUME_NONNULL_END
