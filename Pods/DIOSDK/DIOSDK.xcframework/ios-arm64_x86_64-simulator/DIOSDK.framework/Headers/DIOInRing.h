//
//  DIOInFeedVast.h
//  DIOSDK
//
//  Created by Ariel Malka on 4/23/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <DIOSDK/DIOAdUnit.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOInRing : DIOAdUnit 

+ (DIOAdUnit*)factoryWithSubtype:(NSString*)subtype data:(id)data;

-(void)play;
-(void)pause;

@end

NS_ASSUME_NONNULL_END
