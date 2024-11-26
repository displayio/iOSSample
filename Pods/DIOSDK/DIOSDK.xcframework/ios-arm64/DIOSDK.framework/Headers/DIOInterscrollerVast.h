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
#import <DIOSDK/DIOMediaPreloader.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOInterscrollerVast : DIOVideoAd <DIOMediaPlayerDelegate, DIOMediaPreloaderDelegate, DIOInterscrollerViewDelegate>

@property (nonatomic, strong) DIOInterscrollerVideoPlayer *player;

@end

NS_ASSUME_NONNULL_END
