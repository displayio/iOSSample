//
//  DIOInterscrollerHtml.h
//  DIOSDK
//
//  Created by Ariel Malka on 11/18/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <DIOSDK/DIOHtmlAd.h>
#import <DIOSDK/DIOInterscrollerView.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOInterscrollerHtml : DIOHtmlAd <DIOInterscrollerViewDelegate>

@property (nonatomic) BOOL closed;

@end

NS_ASSUME_NONNULL_END
