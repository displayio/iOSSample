//
//  DIOVideoCell.h
//  DIOSDK
//
//  Created by Ariel Malka on 4/14/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <AVFoundation/AVFoundation.h>

#import "DIOCell.h"
#import "DIOBannerVideoPlayer.h"
#import "DIOTableAdapter.h"

NS_ASSUME_NONNULL_BEGIN

@interface DIOVideoCell : DIOCell

- (void)attachVideoPlayer:(DIOBannerVideoPlayer*)player adapter:(DIOTableAdapter*)adapter fullWidth:(BOOL)fullWidth;

@end

NS_ASSUME_NONNULL_END
