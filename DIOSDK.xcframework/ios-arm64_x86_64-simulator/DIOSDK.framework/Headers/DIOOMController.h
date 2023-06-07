//
//  DIOOMController.h
//  DIOSDK
//
//  Created by Ariel Malka on 2/19/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "DIOVideoPlayer.h"

NS_ASSUME_NONNULL_BEGIN

@interface DIOOMController : NSObject

@property (nonatomic, strong) OMIDDisplayioPartner *partner;

+ (DIOOMController*)sharedInstance;

- (void)initialize;
- (OMIDDisplayioAdSession*)createHtmlAdSessionWithWebView:(UIView*)webView friendlyView:(UIView*)closeButtonView;
- (NSString*)injectScriptContentIntoHtmlWithMarkUp:(NSString*)markup;
- (void)callVideoEvent:(OMIDDisplayioMediaEvents*)videoEvents event:(DIOVideoPlayerEvent)event player:(DIOVideoPlayer*)player;
- (OMIDDisplayioAdSession*)createVideoAdSessionWithVideoView:(UIView*)videoView verifications:(NSArray*)verifications;
- (void)impressionOccuredWithAdSession:(OMIDDisplayioAdSession*)adSession adEvents:(OMIDDisplayioAdEvents*) adEvents;

@end

NS_ASSUME_NONNULL_END
