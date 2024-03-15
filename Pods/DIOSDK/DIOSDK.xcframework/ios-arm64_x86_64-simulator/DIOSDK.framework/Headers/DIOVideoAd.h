//
//  DIOVideoAd.h
//  DIOSDK
//
//  Created by Ariel Malka on 2/26/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <DIOSDK/DIOAdUnit.h>
#import <DIOSDK/DIOVideoPlayer.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOEndCard: NSObject

@property (nonatomic, strong) NSString *resource;
@property (nonatomic, strong, nullable) NSString *clickUrl;
@property (nonatomic, strong, nullable) NSString *endCardlickTracking;
@property (nonatomic, strong, nullable) UIImage *image;

- (instancetype)initWithData:(id)data;
- (void)preloadWithCompletionHandler:(void (^)(void))completionHandler;

@end


@interface DIOVideoAd : DIOAdUnit

@property (nonatomic, strong) id videoData;
@property (nonatomic, strong) id videoParams;
@property (nonatomic, strong) NSString *url;
@property (nonatomic, strong) NSString *clickURL;
@property (nonatomic, strong, nullable) DIOEndCard *endCard;

- (void)parseMediaFile;
- (void)triggerOmLoadedEvent;
- (void)createVideoAdSession:(DIOVideoPlayer*) videoPlayer;
- (void)replaceVideoWithEndcard;
- (UIView*)createEndcardView;
- (id)getVideoEvents;

@end

NS_ASSUME_NONNULL_END
