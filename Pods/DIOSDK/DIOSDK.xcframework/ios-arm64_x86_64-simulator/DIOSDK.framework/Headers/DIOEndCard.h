//
//  DioEndCadrd.h
//  DIOSDK
//
//  Created by rdorofeev on 8/16/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <DIOSDK/DIOInterstitialHtml.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOEndCard : DIOInterstitialHtml
- (instancetype)initWithRequestId:(NSString*)requestId data:(id)data offering:(id)offering;
@end

NS_ASSUME_NONNULL_END
