//
//  DIOMediumRectangleHtml.h
//  DIOSDK
//
//  Created by Ariel Malka on 12/15/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <DIOSDK/DIOHtmlAd.h>

NS_ASSUME_NONNULL_BEGIN

DEPRECATED_MSG_ATTRIBUTE("MediumRectangle ad unit is deprecated. Use InFeed instead.")
@interface DIOMediumRectangleHtml : DIOHtmlAd

@property (nonatomic) BOOL closed;

@end

NS_ASSUME_NONNULL_END
