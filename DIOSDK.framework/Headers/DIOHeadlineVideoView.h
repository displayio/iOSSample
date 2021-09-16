//
//  DIOHeadlineVideoView.h
//  DIOSDK
//
//  Created by Ariel Malka on 3/8/20.
//  Copyright © 2020 Display.io. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol DIOHeadlineVideoViewDelegate <NSObject>

- (void)didMoveToWindow;
- (void)didActivate;
- (void)didDeactivate;
- (void)didClick;
- (void)didStartResizing;
- (void)didEndResizing;
- (void)didMoveAway;
- (void)measuredImpressionOccured;

@end

@interface DIOHeadlineVideoView : UIView

@property (nonatomic, weak) id<DIOHeadlineVideoViewDelegate> delegate;
@property (nonatomic) BOOL detached;

- (instancetype)initWithParams:(id)params;

- (CGFloat)height;

- (void)setContainedView:(UIView*)view;
- (void)isVideo:(BOOL)isVideo;
- (void)cancel;
- (void)moveAway;
- (void)setConstraintForIndexPath :(NSIndexPath*) index;
- (void)setConstraintForScrollView;

@end

NS_ASSUME_NONNULL_END
