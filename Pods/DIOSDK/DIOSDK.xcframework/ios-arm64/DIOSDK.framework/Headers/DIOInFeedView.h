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

@end

@interface DIOInFeedView : UIView

@property (nonatomic, weak) id<DIOInFeedViewDelegate> delegate;
@property (nonatomic) double ratio;
@property (nonatomic) double heightComplement;

/**
 @return The height of the view when it fills the top view-controller's width
 */
- (CGFloat)height;

- (void)setContainedView:(UIView*)view ratio:(double)ratio heightComplement:(double)heightComplement fullWidth:(BOOL)fullWidth isVideo:(BOOL)isVideo;
- (void)setImressionTrackingPercent:(int) percent;

@end
