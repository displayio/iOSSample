//
//  DIOHtmlCell.h
//  DIOSDK
//
//  Created by Ariel Malka on 6/3/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "DIOCell.h"
#import "DIOBannerHtml.h"

NS_ASSUME_NONNULL_BEGIN

@interface DIOHtmlCell : DIOCell

- (void)attachAd:(DIOBannerHtml*)ad adapter:(DIOTableAdapter*)adapter;

@end

NS_ASSUME_NONNULL_END
