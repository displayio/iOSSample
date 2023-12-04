//
//  DIOInterscrollerVastMockPlacement.h
//  DIOSDK
//
//  Created by Ariel Malka on 2/3/20.
//  Copyright © 2020 Display.io. All rights reserved.
//

#import <DIOSDK/DIOInterscrollerMockPlacement.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOInterscrollerVastMockPlacement : DIOInterscrollerMockPlacement

@property (nonatomic, strong) NSURL *videoURL;
@property (nonatomic) CGSize videoSize;
@property (nonatomic) double videoDuration;
@property (nonatomic, strong) NSURL *clickURL;

@end

NS_ASSUME_NONNULL_END
