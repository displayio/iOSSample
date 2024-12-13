//
//  DIOBannerView.h
//  DIOSDK
//
//  Created by Ariel Malka on 11/28/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol DIOBannerViewDelegate <NSObject>

- (void)didMoveToWindow;
- (void)deviceOrientationDidChange;

@end

@interface DIOBannerView : UIView

@property (nonatomic, weak) id<DIOBannerViewDelegate> delegate;

- (void)setContainedView:(UIView*)view width:(double)width height:(double)height;


@end

NS_ASSUME_NONNULL_END
