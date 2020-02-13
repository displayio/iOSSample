//
//  DIOInterscrollerVast.h
//  DIOSDK
//
//  Created by Ariel Malka on 11/18/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import "DIOVideoAd.h"
#import "DIOInterscrollerVideoPlayer.h"
#import "DIOInterscrollerView.h"

NS_ASSUME_NONNULL_BEGIN

@interface DIOInterscrollerVast : DIOVideoAd <DIOVideoPlayerDelegate, DIOInterscrollerViewDelegate>

@property (nonatomic, strong) DIOInterscrollerVideoPlayer *player;
@property (nonatomic, weak) DIOInterscrollerView *containerView;

@end

NS_ASSUME_NONNULL_END
