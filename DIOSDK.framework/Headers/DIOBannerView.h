//
//  DIOBannerView.h
//  DIOSDK
//
//  Created by Ariel Malka on 21/07/2019.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol DIOBannerViewDelegate <NSObject>

@optional

- (void)didMoveToWindow;
- (void)didMoveFromWindow;
- (void)exposureDidChange:(int)exposure;
- (void)deviceOrientationDidChange;
- (void)didActivate;
- (void)didDeactivate;

@end

@interface DIOBannerView : UIView

@property (nonatomic, weak) id<DIOBannerViewDelegate> delegate;
@property (nonatomic) double ratio;
@property (nonatomic) double heightComplement;

- (void)setContainedView:(UIView*)containedView ratio:(double)ratio heightComplement:(double)heightComplement fullWidth:(BOOL)fullWidth;
- (double)height;

@end
