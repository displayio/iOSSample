//
//  DIOOMController.h
//  DIOSDK
//
//  Created by Ariel Malka on 2/19/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "OMIDImports.h"

#import "DIOVideoPlayer.h"

NS_ASSUME_NONNULL_BEGIN

@interface DIOOMController : NSObject

+ (DIOOMController*)sharedInstance;

- (void)initialize;
- (OMIDDisplayioAdSession*)createHtmlAdSessionAndStartWithWebView:(UIView*)webView closeButtonView:(UIView*)closeButtonView;
- (NSString*)injectScriptContentIntoHtmlWithMarkUp:(NSString*)markup;
- (void)callVideoEvent:(OMIDDisplayioVideoEvents*)videoEvents event:(DIOVideoPlayerEvent)event player:(DIOVideoPlayer*)player;
- (OMIDDisplayioAdSession*)createVideoAdSessionWithVideoView:(UIView*)videoView verifications:(NSArray*)verifications;
- (void)impressionOccuredWithAdSession:(OMIDDisplayioAdSession*)adSession;

@end

NS_ASSUME_NONNULL_END
