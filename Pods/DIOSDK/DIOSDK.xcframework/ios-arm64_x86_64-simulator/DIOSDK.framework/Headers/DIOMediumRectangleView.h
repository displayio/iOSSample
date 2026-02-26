//
//  DIOMediumRectangleView.h
//  DIOSDK
//
//  Created by Ariel Malka on 12/15/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol DIOMediumRectangleViewDelegate <NSObject>

- (void)didMoveToWindow;
- (void)deviceOrientationDidChange;

@end

DEPRECATED_MSG_ATTRIBUTE("MediumRectangle ad unit is deprecated. Use InFeed instead.")
@interface DIOMediumRectangleView : UIView

@property (nonatomic, weak) id<DIOMediumRectangleViewDelegate> delegate;

- (void)setContainedView:(UIView*)view width:(double)width height:(double)height;

@end

NS_ASSUME_NONNULL_END
