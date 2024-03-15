//
//  DIOHeadlineHtml.h
//  DIOSDK
//
//  Created by Sergei Morozov on 25.01.22.
//  Copyright © 2022 Display.io. All rights reserved.
//

#import <DIOSDK/DIOHtmlAd.h>
#import <DIOSDK/DIOHeadlineView.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOHeadlineHtml : DIOHtmlAd <DIOHeadlineViewDelegate>

@property (nonatomic) BOOL closed;
@property (nonatomic, weak) DIOHeadlineView *containerView;
@property (nonatomic) BOOL headlineMode;
@property (nonatomic) BOOL allowSwipeOff;
@end

NS_ASSUME_NONNULL_END
