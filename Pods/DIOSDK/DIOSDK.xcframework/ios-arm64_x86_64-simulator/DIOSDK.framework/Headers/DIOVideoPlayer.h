//
//  DIOVideoPlayer.h
//  DIOSDK
//
//  Created by Ariel Malka on 4/25/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <UIKit/UIKit.h>


NS_ASSUME_NONNULL_BEGIN

@interface TimeEvent : NSObject

@property (nonatomic) double time; // Normalized (between 0 and 1)
@property (nonatomic) int quartile;
@property (nonatomic, strong) NSString *beacon;

- (instancetype)initWithTime:(double)time quartile:(int)value;
- (instancetype)initWithTime:(double)time beacon:(NSString*)value;

@end

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

@property (nonatomic, strong) AVPlayer *player;
@property (nonatomic, strong) NSArray *progressEvents;
@property (nonatomic, strong) id eventBeacons;

/*
 * https://developer.apple.com/documentation/avfoundation/media_assets_playback_and_editing/observing_the_playback_time?language=objc
 */
@property (nonatomic, strong) id periodicTimeObserver;
@property (nonatomic, strong) id boundaryTimeObserver;

@property (nonatomic) int periodicTimeObserverTicks;
@property (nonatomic) int boundaryTimeObserverTicks;

@property (nonatomic) double durationInSeconds;
@property (nonatomic) BOOL muted;
@property (nonatomic) BOOL loopVideo;

- (float)volumeLevel;
- (double)duration;

- (void)loadEvents:(id)events;
- (void)setupTimeEventsWithDuration:(CMTime)duration;
- (void)castEvent:(DIOVideoPlayerEvent)event;
- (void)impression;
- (void)startWithURL:(NSURL*)url;
- (UIView*)view;

@end

NS_ASSUME_NONNULL_END
