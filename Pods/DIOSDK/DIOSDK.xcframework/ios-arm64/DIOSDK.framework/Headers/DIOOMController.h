//
//  DIOOMController.h
//  DIOSDK
//
//  Created by Ariel Malka on 2/19/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIOOMController : NSObject

@property (nonatomic, strong) NSString *jsServiceContent;

+ (DIOOMController*)sharedInstance;

- (void)initialize;
- (NSString*) partnerName;
- (NSString*)injectScriptContentIntoHtmlWithMarkUp:(NSString*)markup;

@end

NS_ASSUME_NONNULL_END
