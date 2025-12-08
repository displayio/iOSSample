//
//  DIOInterscrollerVideoPlayer.h
//  DIOSDK
//
//  Created by Ariel Malka on 11/20/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <DIOSDK/DIOMediaPlayer.h>
#import <DIOSDK/DIOPlayerView.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOInterscrollerVideoPlayer : DIOMediaPlayer

- (instancetype)initWithAd:(id) ad;

- (void)activate;
- (void)deactivate;
- (void)toggleSound:(BOOL) isEnabled;
- (void)updateCTAButtonText:(NSString*) text;

@end

NS_ASSUME_NONNULL_END
