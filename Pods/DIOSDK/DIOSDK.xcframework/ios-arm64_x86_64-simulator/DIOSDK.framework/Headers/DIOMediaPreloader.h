//
//  DIOVideoPreloader.h
//  DIOSDK
//
//  Created by Ariel Malka on 3/10/20.
//  Copyright © 2020 Display.io. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol DIOMediaPreloaderDelegate <NSObject>

- (void)mediaPreloadDidSucceedWithURL:(NSURL*)url;
- (void)mediaPreloadDidFailWithError:(NSError*)error;

@end

@interface DIOMediaPreloader : NSObject

@property (nonatomic, weak) id<DIOMediaPreloaderDelegate> delegate;

- (void)preloadWithURL:(NSURL*)url;

@end

NS_ASSUME_NONNULL_END
