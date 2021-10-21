//
//  PlacementViewController.m
//  iOSSample
//
//  Created by Ariel Malka on 5/5/19.
//  Copyright © 2019 Display.io. All rights reserved.
//

#import "PlacementViewController.h"
#import "PlacementType.h"
#import "AdViewController.h"
#import "InterscrollerViewController.h"
#import "HeadlineVideoViewController.h"

@implementation PlacementViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self.tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:@"Cell"];
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return [self.data count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"Cell" forIndexPath:indexPath];
    
    switch ([self.data[indexPath.row][@"type"] integerValue]) {
        case PlacementTypeInterstitial:
            cell.textLabel.text = @"Interstitial";
            break;
            
        case PlacementTypeInFeed:
            cell.textLabel.text = @"In-feed";
            break;
            
        case PlacementTypeInterscroller:
            cell.textLabel.text = @"Interscroller";
            break;
            
        case PlacementTypeBanner:
            cell.textLabel.text = @"Banner";
            break;
            
        case PlacementTypeMediumRectangle:
            cell.textLabel.text = @"Medium Rectangle";
            break;
            
        case PlacementTypeHeadlineVideo:
            cell.textLabel.text = @"Headline Video";
            break;    }
    
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    [tableView deselectRowAtIndexPath:indexPath animated:YES];

    NSString *placementId = self.data[indexPath.row][@"id"];
    PlacementType placementType = [self.data[indexPath.row][@"type"] integerValue];
    
    if (placementType == PlacementTypeInterscroller) {
        InterscrollerViewController *viewController = [InterscrollerViewController new];
        viewController.placementId = placementId;

        UINavigationController *navigationController = [[UINavigationController alloc] initWithRootViewController:viewController];
        navigationController.modalTransitionStyle = UIModalTransitionStyleFlipHorizontal;
        navigationController.modalPresentationStyle = UIModalPresentationFullScreen;
        [self presentViewController:navigationController animated:YES completion:nil];
    } else if (placementType == PlacementTypeHeadlineVideo) {
        HeadlineVideoViewController *viewController = [HeadlineVideoViewController new];
        viewController.placementId = placementId;

        UINavigationController *navigationController = [[UINavigationController alloc] initWithRootViewController:viewController];
        navigationController.modalTransitionStyle = UIModalTransitionStyleFlipHorizontal;
        navigationController.modalPresentationStyle = UIModalPresentationFullScreen;
        [self presentViewController:navigationController animated:YES completion:nil];
    } else {
        AdViewController *adViewController = (AdViewController*)[[UIStoryboard storyboardWithName:@"Main" bundle:nil] instantiateViewControllerWithIdentifier:@"AdViewController"];
        adViewController.placementId = placementId;
        adViewController.placementType = placementType;
        
        [self.navigationController pushViewController:adViewController animated:YES];
    }
}

@end
