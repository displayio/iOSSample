//
//  DIOPlayerView.h
//  DIOSDK
//
//  Created by Ariel Malka on 2/10/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOPlayerView : UIView

@property (readonly) AVPlayerLayer *playerLayer;

@end

NS_ASSUME_NONNULL_END
