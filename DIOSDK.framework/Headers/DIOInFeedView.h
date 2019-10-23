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
- (void)didMoveFromWindow;
- (void)exposureDidChange:(int)exposure;
- (void)deviceOrientationDidChange;
- (void)didActivate;
- (void)didDeactivate;

@end

@interface DIOInFeedView : UIView

@property (nonatomic, weak) id<DIOInFeedViewDelegate> delegate;
@property (nonatomic) double ratio;
@property (nonatomic) double heightComplement;

/**
 @return The height of the view when it fills the top view-controller's width
 */
- (double)height;

- (void)setContainedView:(UIView*)containedView ratio:(double)ratio heightComplement:(double)heightComplement fullWidth:(BOOL)fullWidth;

@end
