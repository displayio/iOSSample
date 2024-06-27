//
//  DIOHtmlAd.h
//  DIOSDK
//
//  Created by Ariel Malka on 2/25/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <DIOSDK/DIOAdUnit.h>
#import <DIOSDK/DIOCustomWebView.h>
#import <DIOSDK/DIOMRAIDView.h>
#import <DIOSDK/DIOMRAIDVideoPlayer.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOHtmlAd : DIOAdUnit <WKNavigationDelegate, WKUIDelegate, WKScriptMessageHandler, DIOMRAIDVideoPlayerDelegate>

@property (nonatomic, strong) DIOCustomWebView *webView;
@property (nonatomic, strong) DIOMRAIDView *mraidView;
@property (nonatomic, strong) DIOMRAIDVideoPlayer *videoPlayer;

@property (nonatomic) BOOL fallbackTriggered;
@property (nonatomic) BOOL scaleWebviewToAd;

- (void)executeJavascript:(NSString*)javascript, ...;

- (void)close2;
- (void)unload;
- (void)playVideoWithURL:(NSURL*)url;
- (void)useCustomClose:(BOOL)b;
- (void)fallback;
- (void)openWithURLString:(NSString*)urlString;

- (void)updateExpandPropertiesWithWidth:(int)width height:(int)height;
- (void)updateMaxSizeWithWidth:(int)width height:(int)height;
- (void)updateCurrentPositionWithWidth:(int)width height:(int)height;
- (void)updateDefaultPositionWithWidth:(int)width height:(int)height;

- (void)updateProperties;
- (void)updateExpandProperties;
- (void)updateMaxSize;
- (void)updateScreenSize;
- (void)updateCurrentPosition;
- (void)updateDefaultPosition;
- (void)updateCurrentAppOrientation;
- (void)updateOrientationProperties;

- (void)triggerReady;
- (void)triggerViewableChangeWithIsViewable:(BOOL)isViewable;
- (void)triggerStateChangeWithState:(NSString*)state;
- (void)triggerExposureChangeWithExposure:(int)exposure x:(int)x y:(int)y width:(int)width height:(int)height;
- (void)triggerSizeChangeWithWidth:(int)width height:(int)height;
- (void)triggerErrorWithMessage:(NSString*)message action:(NSString*)action;
- (void)createHtmlAdSessionWithFriendlyView:(UIView*) friendlyView;


@end

NS_ASSUME_NONNULL_END
