//
//  DIOMRAIDVideoPlayer.h
//  DIOSDK
//
//  Created by Ariel Malka on 6/12/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol DIOMRAIDVideoPlayerDelegate <NSObject>

- (void)videoPlayerDidFailWithError:(NSError*)error;
- (void)videoPlayerDidSkip;
- (void)videoPlayerDidEnd;

@end

@interface DIOMRAIDVideoPlayer : NSObject

@property (nonatomic, strong) id<DIOMRAIDVideoPlayerDelegate> delegate;

- (instancetype)initWithHostView:(UIView*)hostView params:(id)params;
- (void)removeFromHostView;
- (void)startWithURL:(NSURL*)url;

@end

NS_ASSUME_NONNULL_END
