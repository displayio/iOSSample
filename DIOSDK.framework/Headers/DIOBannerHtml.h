//
//  DIOBannerHtml.h
//  DIOSDK
//
//  Created by Ariel Malka on 6/3/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "DIOHtmlAd.h"
#import "DIOBannerView.h"

NS_ASSUME_NONNULL_BEGIN

@interface DIOBannerHtml : DIOHtmlAd <DIOBannerViewDelegate>

@property (nonatomic) BOOL closed;

@end

NS_ASSUME_NONNULL_END