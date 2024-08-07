//
//  InterscrollerViewController.m
//  iOSSample
//
//  Created by Ariel Malka on 1/12/20.
//  Copyright © 2020 Display.io. All rights reserved.
//

#import "InterscrollerViewController.h"

#import <DIOSDK/DIOController.h>
#import <DIOSDK/DIOInterscrollerContainer.h>
#import <DIOSDK/DIOInterscrollerPlacement.h>

@interface InterscrollerViewController ()

@property (nonatomic, strong) DIOInterscrollerContainer *container;

@property (nonatomic, strong) DIOAd *ad;

@end

@implementation InterscrollerViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self.tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:@"IDENTIFIER"];
    [self.tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:@"AD"];
    
    self.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:@"Close" style:UIBarButtonItemStylePlain target:self action:@selector(close:)];
    
    self.navigationController.navigationBar.translucent = NO;
    
}

- (void)viewDidAppear:(BOOL)animated {
    DIOInterscrollerPlacement* interscrollerPlacement = (DIOInterscrollerPlacement*)[[DIOController sharedInstance] placementWithId:self.placementId];

    if (self.isORTB) {
        [interscrollerPlacement loadInterscrollerFromORTB:[self getSampleOrtbResponse]
                                                              adReceivedHandler:^(DIOAd *ad, DIOInterscrollerContainer *container) {
            self.container = container;
            self.ad = ad;
        }
                                                                    noAdHandler:^(NSError *error) {
            NSLog(@"Error loading ad");
        }];
    } else {
        
        DIOAdRequest *request = [interscrollerPlacement newAdRequest];
        
        self.container = [[DIOInterscrollerContainer alloc] init];
        
        [self.container loadWithAdRequest:request completionHandler:^(DIOAd *ad){
            self.ad = ad;
        } errorHandler:^(NSError *error) {
            NSLog(@"%@", error);
        }];
    }
}

- (void)close:(id)sender {
    if (self.ad) {
        [self.ad finish];
    }
    
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return 40;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    if (indexPath.row == 20) {
        UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"AD" forIndexPath:indexPath];
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
        
        UIView *view = [self.container view];
        
        if (cell.contentView.subviews.count > 0) [cell.contentView.subviews[0] removeFromSuperview];
        [cell.contentView addSubview:view];
        
        return cell;
    }
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"IDENTIFIER" forIndexPath:indexPath];
    cell.selectionStyle = UITableViewCellSelectionStyleNone;
    cell.textLabel.text = [NSString stringWithFormat:@"%ld", indexPath.row];
    
    return cell;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return UITableViewAutomaticDimension;
}

    //just a mock bid response to demonstrate how to render oRTB ads on DIO SDK
- (id)getSampleOrtbResponse {
    // Randomize id. Having a unique id is essential to avoid collisions between different ads
    int rnd = arc4random_uniform(10000);
    NSString *rndString = [NSString stringWithFormat:@"%d", rnd];

    NSString *response = [NSString stringWithFormat:
                          @"{"
                          @"    \"id\": \"7d79e65e-26c5-4153-93e1-cb59faaecefc%@\","
                          @"    \"seatbid\": ["
                          @"        {"
                          @"            \"bid\": ["
                          @"                {"
                          @"                    \"id\": \"12345\","
                          @"                    \"impid\": \"6452af6d894ce\","
                          @"                    \"price\": 4.034800000000001,"
                          @"                    \"nurl\": \"http:\\/\\/example.com\\/winnoticeurl&price=${AUCTION_PRICE}&id=${AUCTION_ID}&impid=${AUCTION_IMP_ID}&bidid=${AUCTION_BID_ID}&seatid=${AUCTION_SEAT_ID}&curr=${AUCTION_CURRENCY}\","
                          @"                    \"adm\": \"<?xml version=\\\"1.0\\\"?>\\n<VAST version=\\\"3.0\\\"> <Ad id=\\\"2799063\\\"> <InLine> <AdSystem version=\\\"1.0\\\"> <![CDATA[AdServer]]> <\\/AdSystem> <AdTitle> <![CDATA[Video Ad]]> <\\/AdTitle> <Impression> <![CDATA[https:\\/\\/geo-tracker.smadex.com\\/hyperad\\/rtb\\/111285\\/impression\\/17-H4sIAAAAAAAAAI2SPWgUQRTHN4_zOI8zATmChZhoo4WzzOfOzhXmEnKYYBElIYXNMft1Wdi9O2_34ndhoY1oFWzSWFlYpE5n0EorLcROSWEVED8glYhzq0IECwemeDP_997__Xiw8WAKLMuCY3E3DwdZHuexTkz8fBtgfpihUGc5ojbBOM1aNiZYegSrSPue7weCQFMnnd4gztdS1NFp3O0gP9fI72sUd7NcJ8l_KL5_-PGiBpXUy6_Ck0ebY7A3cXhiov5lBp6OrVN00NnBvFvUllK50mWyhcTZfxc3IiKFcojk0qHccbnRwrdnH-8debN_bjS6OZ9nAIhlLgCUoLz17i1YpfkW1If9JI7y9sjk7o361vndrzNQWTdIoETUKBMmiesaOtJ2bGxBdbbfT0KoxRfXet0QynEvgxrhtpFYUM9SPcj7xQ_AGT2StuMibq-HA8LbLhwP4qyf6Ot23Jtenr8AVWYLW4H126hpuBrRBmMixCQizKc8lCIwCFQoqKe0wkQEfhAGKuC-KPLgKMOCccYxh8f7rypQXZydM-6h4jLuGif1lWHqJYN2vLQMTamUI33CsMscrCPHdR1fR77gLom0CgIYp5QpIqkZsts2Mzx8uXH_tOljCn3aPASvN04BcBPuvL9ThR2zRX8Q1wgh1BVGN04dilaXCEzO6WB6oZd6w0Hn76AMmGLKEOaIqBXiNDBrYGorLi4vaBVxabCjIPQ9REgYIFczD3EV4cDhkgdEwdTdvUvbJxabwIpzsgmlhRaUDY6qQ5jAVoEUKqMuVuG6oDs9WsJGHpqlv4I8s0Ojx9LN279IXvsJ3XT5Zi8DAAA\\/1\\/a9f47188-decb-11ed-8a3b-49f0d6474d19\\/0.200010\\/notify?cid=279848]]> <\\/Impression> <Creatives> <Creative id=\\\"1\\\" sequence=\\\"1\\\"> <Linear skipoffset=\\\"00:00:05\\\"> <Duration>00:00:27<\\/Duration> <TrackingEvents> <Tracking event=\\\"start\\\"> <![CDATA[https:\\/\\/geo-tracker.smadex.com\\/hyperad\\/tracking\\/action\\/start?click_id=66936789946c8b4ced0ac07e9330d097e59bf0a7c7db4afa766f9075e45445473e7582a2411a73b12d36a7e675db25ea8c32f8d1ea636d91814db548dff280610e966f156a78c35d767b203d6719f30975be78cd33486a3222e6ece5459e2527fe5e420e906930e79e037845d55f9833c3f4d554cd60422399044fa9336cfa4fc994230edfc82cc746d9a29a12fb0c4829341c45aeda13c2d3d05f513dc64afd3b9fcd667c7f6eea3844a6a687c65b72a7affd5e0b451e14fdcaa69141efcf0b&crid=2799063]]> <\\/Tracking> <Tracking event=\\\"firstQuartile\\\"> <![CDATA[https:\\/\\/geo-tracker.smadex.com\\/hyperad\\/tracking\\/action\\/firstQuartile?click_id=66936789946c8b4ced0ac07e9330d097e59bf0a7c7db4afa766f9075e45445473e7582a2411a73b12d36a7e675db25ea8c32f8d1ea636d91814db548dff280610e966f156a78c35d767b203d6719f30975be78cd33486a3222e6ece5459e2527fe5e420e906930e79e037845d55f9833c3f4d554cd60422399044fa9336cfa4fc994230edfc82cc746d9a29a12fb0c4829341c45aeda13c2d3d05f513dc64afd3b9fcd667c7f6eea3844a6a687c65b72a7affd5e0b451e14fdcaa69141efcf0b&crid=2799063]]> <\\/Tracking> <Tracking event=\\\"midpoint\\\"> <![CDATA[https:\\/\\/geo-tracker.smadex.com\\/hyperad\\/tracking\\/action\\/midpoint?click_id=66936789946c8b4ced0ac07e9330d097e59bf0a7c7db4afa766f9075e45445473e7582a2411a73b12d36a7e675db25ea8c32f8d1ea636d91814db548dff280610e966f156a78c35d767b203d6719f30975be78cd33486a3222e6ece5459e2527fe5e420e906930e79e037845d55f9833c3f4d554cd60422399044fa9336cfa4fc994230edfc82cc746d9a29a12fb0c4829341c45aeda13c2d3d05f513dc64afd3b9fcd667c7f6eea3844a6a687c65b72a7affd5e0b451e14fdcaa69141efcf0b&crid=2799063]]> <\\/Tracking> <Tracking event=\\\"thirdQuartile\\\"> <![CDATA[https:\\/\\/geo-tracker.smadex.com\\/hyperad\\/tracking\\/action\\/thirdQuartile?click_id=66936789946c8b4ced0ac07e9330d097e59bf0a7c7db4afa766f9075e45445473e7582a2411a73b12d36a7e675db25ea8c32f8d1ea636d91814db548dff280610e966f156a78c35d767b203d6719f30975be78cd33486a3222e6ece5459e2527fe5e420e906930e79e037845d55f9833c3f4d554cd60422399044fa9336cfa4fc994230edfc82cc746d9a29a12fb0c4829341c45aeda13c2d3d05f513dc64afd3b9fcd667c7f6eea3844a6a687c65b72a7affd5e0b451e14fdcaa69141efcf0b&crid=2799063]]> <\\/Tracking> <Tracking event=\\\"complete\\\"> <![CDATA[https:\\/\\/geo-tracker.smadex.com\\/hyperad\\/tracking\\/action\\/complete?click_id=66936789946c8b4ced0ac07e9330d097e59bf0a7c7db4afa766f9075e45445473e7582a2411a73b12d36a7e675db25ea8c32f8d1ea636d91814db548dff280610e966f156a78c35d767b203d6719f30975be78cd33486a3222e6ece5459e2527fe5e420e906930e79e037845d55f9833c3f4d554cd60422399044fa9336cfa4fc994230edfc82cc746d9a29a12fb0c4829341c45aeda13c2d3d05f513dc64afd3b9fcd667c7f6eea3844a6a687c65b72a7affd5e0b451e14fdcaa69141efcf0b&crid=2799063]]> <\\/Tracking> </TrackingEvents> <VideoClicks> <ClickThrough> <![CDATA[https:\\/\\/geo-tracker.smadex.com\\/hyperad\\/rtb\\/click?click_id=66936789946c8b4ced0ac07e9330d097e59bf0a7c7db4afa766f9075e45445473e7582a2411a73b12d36a7e675db25ea8c32f8d1ea636d91814db548dff280610e966f156a78c35d767b203d6719f30975be78cd33486a3222e6ece5459e2527fe5e420e906930e79e037845d55f9833c3f4d554cd60422399044fa9336cfa4fc994230edfc82cc746d9a29a12fb0c4829341c45aeda13c2d3d05f513dc64afd3b9fcd667c7f6eea3844a6a687c65b72a7affd5e0b451e14fdcaa69141efcf0b]]> <\\/ClickThrough> </VideoClicks> <MediaFiles> <MediaFile delivery=\\\"progressive\\\" type=\\\"video/mp4\\\" bitrate=\\\"500\\\" width=\\\"400\\\" height=\\\"300\\\" scalable=\\\"true\\\" maintainAspectRatio=\\\"true\\\"> <![CDATA[https:\/\/d3jdaktv9qp9iu.cloudfront.net\/c\/CjTxsB2oAobxX6SSNa8uhxjy.mp4]]> <\\/MediaFile> </MediaFiles> </Linear> </Creative> </Creatives> </InLine> </Ad> </VAST>\""
                          @"                }"
                          @"            ]"
                          @"        }"
                          @"    ]"
                          @"}", rndString];
    
    
    NSData *data = [response dataUsingEncoding:NSUTF8StringEncoding];
    id json = [NSJSONSerialization JSONObjectWithData:data options:0 error:nil];
    return json;
}

@end
