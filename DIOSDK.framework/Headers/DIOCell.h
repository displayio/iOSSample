//
//  DIOCell.h
//  DIOSDK
//
//  Created by Ariel Malka on 4/22/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOCell : UITableViewCell

- (void)cellDidActivate;
- (void)cellDidDeactivate;
- (void)cellExposureDidChange:(int)exposure;
- (void)tableViewDidTransitionToSize:(CGSize)size;

@end

NS_ASSUME_NONNULL_END
