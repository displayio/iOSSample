//
//  DIOVideoPlayer.h
//  DIOSDK
//
//  Created by Ariel Malka on 2/20/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "OMIDImports.h"

#import "DIOPlayerView.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, DIOVideoPlayerEvent) {
    DIOVideoPlayerEventStart,
    DIOVideoPlayerEventFirstQuartile,
    DIOVideoPlayerEventMidpoint,
    DIOVideoPlayerEventThirdQuartile,
    DIOVideoPlayerEventComplete,
    DIOVideoPlayerEventMute,
    DIOVideoPlayerEventUnmute,
    DIOVideoPlayerEventSkip,
    DIOVideoPlayerEventClick,
    DIOVideoPlayerEventClose,
    DIOVideoPlayerEventResume,
    DIOVideoPlayerEventPause,
    DIOVideoPlayerEventImpression
};

@class DIOVideoPlayer;

@protocol DIOVideoPlayerDelegate <NSObject>

- (void)videoPlayerDidFailWithError:(NSError*)error;
- (void)videoPlayerDidCancel;
- (void)videoPlayerReadyToPlayWithDuration:(double)duration;
- (void)videoPlayerEvent:(DIOVideoPlayerEvent)event;

@end

@interface DIOVideoPlayer : NSObject

@property (nonatomic, strong) id<DIOVideoPlayerDelegate> delegate;
@property (nonatomic, strong) OMIDDisplayioVideoEvents *omVideoEvents;

- (instancetype)initWithHostView:(UIView*)hostView params:(id)params;
- (void)startWithURL:(NSURL*)url;
- (void)loadEvents:(id)events;
- (float)volumeLevel;
- (double)duration;
- (UIView*)view;
- (void)impression;

@end

NS_ASSUME_NONNULL_END
