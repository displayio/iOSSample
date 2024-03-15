//
//  DIOServiceClient.h
//  DIOSDK
//
//  Created by Ariel Malka on 2/13/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOServiceClient : NSObject

@property (nonatomic, strong) NSString *urlString;

- (void)placementsForAppId:(NSString*)appId completionHandler:(void (^)(id, NSError*))completionHandler;
- (void)getAdForPlacementId:(NSString*)placementId data:(id)data completionHandler:(void (^)(id, NSError*))completionHandler;
- (void)reportErrorForAppId:(NSString*)appId messageLog:(NSString*)messageLog error:(NSString*)error trace:(NSString*)trace data:(id)data level:(NSString*)level;
- (void)reportWithScreenCapture:(NSString*)reportUrl data:(id)data completionHandler:(void (^)(id, NSError*))completionHandler;
- (void)addWithKey:(NSString*)key value:(NSString*)value;
- (void)removeWithKey:(NSString*)key;
- (void)callBeaconWithURLString:(NSString*)urlString;

@end

NS_ASSUME_NONNULL_END
