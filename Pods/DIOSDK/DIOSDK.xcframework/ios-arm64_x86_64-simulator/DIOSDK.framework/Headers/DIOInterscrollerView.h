//
//  DIOInterscrollerView.h
//  DIOSDK
//
//  Created by Ariel Malka on 11/5/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <DIOSDK/DIOInterscrollerPlacement.h>

NS_ASSUME_NONNULL_BEGIN

@protocol DIOInterscrollerViewDelegate <NSObject>

- (void)didMoveToWindow;
- (void)didMoveToSuperview;
- (void)exposureDidChange:(int)exposure y:(int)y height:(int)height;
- (void)didActivate;
- (void)didDeactivate;
- (void)trackImpression;
- (void)measuredImpressionOccured;
- (void)deviceOrientationDidChange;
- (void)showSKOverlay;
- (void)dismissSKOverlay;

@end

@interface DIOInterscrollerView : UIView

@property (nonatomic, weak) id<DIOInterscrollerViewDelegate> delegate;


- (instancetype)initWithPlacement:(DIOInterscrollerPlacement*)placement;

- (void)setContainedView:(UIView*)view;
- (void)scaleWebviewToAd:(BOOL)scale;
- (void)isVideo:(BOOL)isVideo;
- (void)applyDwellWithHoldPeriod:(int) holdPeriod;
- (void)setImressionTrackingPercent:(int) percent;
- (void)cancel;
- (int)containerHeight;

@end

NS_ASSUME_NONNULL_END
