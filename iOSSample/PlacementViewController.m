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
            
        case PlacementTypeFeedInterstitial:
            cell.textLabel.text = @"Feed Interstital";
            break;
            
        case PlacementTypeBanner:
            cell.textLabel.text = @"Banner";
            break;
            
        case PlacementTypeMediumRectangle:
            cell.textLabel.text = @"Medium Rectangle";
            break;
    }
    
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    [tableView deselectRowAtIndexPath:indexPath animated:YES];

    AdViewController *adViewController = (AdViewController*)[[UIStoryboard storyboardWithName:@"Main" bundle:nil] instantiateViewControllerWithIdentifier:@"AdViewController"];
    
    adViewController.placementId = self.data[indexPath.row][@"id"];
    adViewController.placementType = [self.data[indexPath.row][@"type"] integerValue];
    
    [self.navigationController pushViewController:adViewController animated:YES];
}

@end
