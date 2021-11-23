//
//  DIOInterscrollerView.h
//  DIOSDK
//
//  Created by Ariel Malka on 11/5/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol DIOInterscrollerViewDelegate <NSObject>

- (void)didMoveToWindow;
- (void)didMoveToSuperview;
- (void)exposureDidChange:(int)exposure y:(int)y height:(int)height;
- (void)didActivate;
- (void)didDeactivate;
- (void)trackImpression;
- (void)measuredImpressionOccured;


@end

@interface DIOInterscrollerView : UIView

@property (nonatomic, weak) id<DIOInterscrollerViewDelegate> delegate;
@property (nonatomic, strong) UIView *footerView;


- (instancetype)initWithParams:(id)params;

- (void)setContainedView:(UIView*)view;
- (void)setScaleWebviewToAd:(BOOL)scale;
- (void)isVideo:(BOOL)isVideo;
- (void)clearBackGround;
- (void)cancel;
- (void)skip;
- (int)containerHeight;
- (void)setConstraintForIndexPath :(NSIndexPath*) index;
-(void) setConstraintForScrollView;
- (void)updateDwellOptionsForAdvertiser:(BOOL)sticky holdPeriod:(NSInteger) holdPeriod;

@end

NS_ASSUME_NONNULL_END
