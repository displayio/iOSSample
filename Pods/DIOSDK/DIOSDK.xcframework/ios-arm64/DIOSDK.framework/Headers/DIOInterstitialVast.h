//
//  DIOInterstitialVast.h
//  DIOSDK
//
//  Created by Ariel Malka on 2/26/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <DIOSDK/DIOVideoAd.h>
#import <DIOSDK/DIOInterstitialVideoPlayer.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOInterstitialVast : DIOVideoAd <DIOMediaPlayerDelegate>

@property (nonatomic) int skippableIn;

@end

NS_ASSUME_NONNULL_END
