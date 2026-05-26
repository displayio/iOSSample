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
- (void)soundControlClicked:(BOOL)isEnabled;
- (void)ctaButtonClicked;

@optional
- (void)didMoveOutOfWindow;

@end

@interface DIOBannerView : UIView

@property (nonatomic, weak) id<DIOBannerViewDelegate> delegate;

- (void)setContainedView:(UIView*)view withAd:(id)ad;
- (void)updateSoundControlState:(BOOL)isEnabled;

@end

NS_ASSUME_NONNULL_END
