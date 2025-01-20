//
//  DIOOMAdSession.h
//  DIOSDK
//
//  Created by Ro Do on 08.06.2023.
//  Copyright © 2023 Display.io. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <DIOSDK/DIOMediaPlayer.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOOMAdSession : NSObject

-(instancetype) initHtmlAdSessionWithWebView:(UIView*)webView friendlyView:(UIView*)friendlyView;
-(instancetype) initVideoAdSessionWithVideoView:(UIView*)videoView verifications:(NSArray*)verifications;
-(void)callVideoEvent:(DIOMediaPlayerEvent)event player:(DIOMediaPlayer*)player;
-(void)callOmLoadedEventForVideo:(bool)isSkipable skipAfter:(double)skipAfter;
-(void)impressionOccuredForSessionWithNotifyLoaded:(bool)notifyLoaded;
-(void)notifyUserInteraction;
-(void)start;
-(void)finish;

@end

NS_ASSUME_NONNULL_END
