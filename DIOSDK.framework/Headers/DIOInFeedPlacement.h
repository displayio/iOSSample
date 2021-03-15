//
//  DIOInFeedPlacement.h
//  DIOSDK
//
//  Created by Ariel Malka on 2/14/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import "DIOPlacement.h"

NS_ASSUME_NONNULL_BEGIN

@interface DIOInFeedPlacement : DIOPlacement

@property (nonatomic) BOOL fullWidth;
@property (nonatomic) BOOL framed;
@property (nonatomic) BOOL showTimer;

@end

NS_ASSUME_NONNULL_END
