//
//  DIOHeadlineView.h
//  DIOSDK
//
//  Created by Ariel Malka on 3/8/20.
//  Copyright © 2020 Display.io. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <DIOSDK/DIOAd.h>
#import <DIOSDK/DIOHeadlinePlacement.h>

NS_ASSUME_NONNULL_BEGIN

@protocol DIOHeadlineViewDelegate <NSObject>

- (void)didMoveToWindow;
- (void)didActivate;
- (void)didDeactivate;
- (void)didClick;
- (void)didStartResizing;
- (void)didEndResizing;
- (void)didMoveAway;
- (void)markImpressed;
- (void)measuredImpressionOccured;
- (void) didSwipedOut;
- (void) didSnapped;
- (void)showSKOverlay;
- (void)dismissSKOverlay;

@end

@interface DIOHeadlineView : UIView

@property (nonatomic, weak) id<DIOHeadlineViewDelegate> delegate;
@property (nonatomic) BOOL detached;

- (instancetype)initWithPlacement:(DIOHeadlinePlacement*)placement;
- (void) updateWithAd :(DIOAd*)ad;

- (CGFloat)height;

- (void)setContainedView:(UIView*)view;
- (void)cancel;
- (void)moveAway;
- (void)setConstraintForIndexPath :(NSIndexPath*) index;
- (void)setConstraintForScrollView;

@end

NS_ASSUME_NONNULL_END
