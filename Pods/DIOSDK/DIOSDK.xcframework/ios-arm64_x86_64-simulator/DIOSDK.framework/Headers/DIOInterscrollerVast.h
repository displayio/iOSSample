//
//  DIOInterscrollerVast.h
//  DIOSDK
//
//  Created by Ariel Malka on 11/18/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <DIOSDK/DIOMediaAd.h>
#import <DIOSDK/DIOInterscrollerVideoPlayer.h>
#import <DIOSDK/DIOInterscrollerView.h>
#import <DIOSDK/DIOMediaPreloader.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOInterscrollerVast : DIOMediaAd <DIOMediaPreloaderDelegate, DIOInterscrollerViewDelegate>

@end

NS_ASSUME_NONNULL_END
