//
//  DIOCustomWebView.h
//  DIOSDK
//
//  Created by Ariel Malka on 5/19/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>

NS_ASSUME_NONNULL_BEGIN

@class DIOHtmlAd;

@interface DIOCustomWebView : WKWebView

@property (nonatomic, weak) DIOHtmlAd *ad;

- (void)loadMarkup:(NSString*)markup;

- (int)width;
- (int)height;

@end

NS_ASSUME_NONNULL_END
