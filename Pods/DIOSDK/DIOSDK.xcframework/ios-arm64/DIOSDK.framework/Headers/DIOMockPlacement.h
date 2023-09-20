//
//  DIOMockPlacement.h
//  DIOSDK
//
//  Created by Ariel Malka on 2/3/20.
//  Copyright © 2020 Display.io. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOMockPlacement : NSObject

@property (nonatomic, strong) NSString *ID;
@property (nonatomic, strong) NSString *type;
@property (nonatomic, strong) NSString *name;

- (instancetype)initWithID:(NSString*)ID;

- (void)updateInitData:(NSMutableDictionary*)initData;
- (NSMutableDictionary*)adResponse;

@end

NS_ASSUME_NONNULL_END
