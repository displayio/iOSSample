//
//  DIOInterscrollerVast.h
//  DIOSDK
//
//  Created by Ariel Malka on 11/18/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <DIOSDK/DIOVideoAd.h>
#import <DIOSDK/DIOInterscrollerVideoPlayer.h>
#import <DIOSDK/DIOInterscrollerView.h>
#import <DIOSDK/DIOVideoPreloader.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOInterscrollerVast : DIOVideoAd <DIOVideoPlayerDelegate, DIOVideoPreloaderDelegate, DIOInterscrollerViewDelegate>

@property (nonatomic, strong) DIOInterscrollerVideoPlayer *player;

@end

NS_ASSUME_NONNULL_END
