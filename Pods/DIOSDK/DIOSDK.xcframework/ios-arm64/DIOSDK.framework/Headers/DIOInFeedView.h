//
//  DIOInFeedView.h
//  DIOSDK
//
//  Created by Ariel Malka on 21/07/2019.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol DIOInFeedViewDelegate <NSObject>

@optional

- (void)didMoveToWindow;
- (void)exposureDidChange:(int)exposure y:(int)y height:(int)height;
- (void)deviceOrientationDidChange;
- (void)didActivate;
- (void)didDeactivate;
- (void)measuredImpressionOccured;
- (void)markImpressed;
- (void)showSKOverlay;
- (void)dismissSKOverlay;
- (void)didMoveAway;
- (void)didClick;
- (void)didGoToHeadlineMode;

@end

@interface DIOInFeedView : UIView

@property (nonatomic, weak) id<DIOInFeedViewDelegate> delegate;

/**
 @return The height of the view when it fills the top view-controller's width
 */
- (CGFloat)height;
- (void)moveAway;
- (void)setUseHeadlineMode:(BOOL) isHeadlineMode;
- (void)setContainedView:(UIView*)view withAd:(id)ad;
- (void)updateCTAButtonText:(NSString*) text;

@end
