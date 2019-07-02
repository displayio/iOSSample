//
//  DIOVideoCell.h
//  DIOSDK
//
//  Created by Ariel Malka on 4/14/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import "DIOCell.h"
#import "DIOBannerVast.h"

NS_ASSUME_NONNULL_BEGIN

@interface DIOVideoCell : DIOCell

- (void)attachAd:(DIOBannerVast*)ad;

@end

NS_ASSUME_NONNULL_END
