//
//  DIOVideoPreloader.h
//  DIOSDK
//
//  Created by Ariel Malka on 3/10/20.
//  Copyright © 2020 Display.io. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol DIOVideoPreloaderDelegate <NSObject>

- (void)videoPreloadDidSucceedWithURL:(NSURL*)url;
- (void)videoPreloadDidFailWithError:(NSError*)error;

@end

@interface DIOVideoPreloader : NSObject

@property (nonatomic, weak) id<DIOVideoPreloaderDelegate> delegate;

- (void)preloadWithURL:(NSURL*)url;

@end

NS_ASSUME_NONNULL_END
