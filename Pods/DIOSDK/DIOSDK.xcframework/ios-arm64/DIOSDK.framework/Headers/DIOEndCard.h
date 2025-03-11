//
//  DIOEndCard.h
//  DIOSDK
//
//  Created by Roman Do on 02.08.2024.
//  Copyright © 2024 Display.io. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIView.h>
#import <WebKit/WebKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol DIOEndCardDelegate <NSObject>

@optional

- (void)endCardTapped:(NSString*)url;

@end

@interface DIOEndCard : NSObject <WKNavigationDelegate, WKUIDelegate>

@property (nonatomic, readonly) int width;
@property (nonatomic, readonly) int height;
@property (nonatomic, weak) id<DIOEndCardDelegate> delegate;


- (instancetype)initWithData:(id)data;
- (void)close;
- (void)markImpressed;
- (UIView*)view;

@end

NS_ASSUME_NONNULL_END
