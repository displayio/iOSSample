//
//  DIOFeedInterstitialView.h
//  DIOSDK
//
//  Created by Ariel Malka on 11/5/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol DIOFeedInterstitialViewDelegate <NSObject>

- (void)didMoveToWindow;
- (void)exposureDidChange:(int)exposure;
- (void)didActivate;
- (void)didDeactivate;

@end

@interface DIOFeedInterstitialView : UIView

@property (nonatomic, weak) id<DIOFeedInterstitialViewDelegate> delegate;

- (instancetype)initWithParams:(id)params;

- (void)setContainedView:(UIView*)view;

@end

NS_ASSUME_NONNULL_END
