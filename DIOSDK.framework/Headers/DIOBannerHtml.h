//
//  DIOBannerHtml.h
//  DIOSDK
//
//  Created by Ariel Malka on 6/3/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "DIOHtmlAd.h"
#import "DIOTableAdapter.h"

NS_ASSUME_NONNULL_BEGIN

@interface DIOBannerHtml : DIOHtmlAd

@property (nonatomic) BOOL closed;
@property (nonatomic, weak) DIOTableAdapter *adapter;
@property (nonatomic, weak) NSLayoutConstraint *mraidViewHeightConstraint;

- (void)activate;
- (void)deactivate;
- (void)cellExposureDidChange:(int)exposure;
- (void)tableViewDidTransitionToSize:(CGSize)size;

@end

NS_ASSUME_NONNULL_END
