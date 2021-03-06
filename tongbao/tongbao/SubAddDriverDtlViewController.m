//
//  SubAddDriverDtlViewController.m
//  tongbao
//
//  Created by ZX on 16/3/28.
//  Copyright © 2016年 ZX. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SubAddDriverDtlViewController.h"
#import "User.h"
#import "SubAddFreqDriverViewController.h"
#import "SubDriverViewController.h"

@interface SubAddDriverDtlViewController ()




@end

@implementation SubAddDriverDtlViewController


- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.driverNameLbl.text = self.driver.nickName;
    self.driverTelLbl.text = self.driver.phoneNum;
    
    self.driverNameLbl.enabled = FALSE;
    self.driverTelLbl.enabled = FALSE;
}



- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
    NSInteger section = indexPath.section;
    NSInteger rowNo = indexPath.row;
    if (section == 0) {
        if (rowNo == 0) {
           
        }
    }else if (section == 1){
        [User addFrequentDriver: self.driver withBlock:^(NSError *error, User *user)
         {
             
             if (error) {
                 NSLog(@"ADD FREQDriver FAILED!!!!");
                 UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"添加失败" message:@"" preferredStyle:UIAlertControllerStyleAlert];
                 UIAlertAction *okAction = [UIAlertAction actionWithTitle:@"好的" style:UIAlertActionStyleDestructive handler:nil];
                 [alertController addAction:okAction];
                 [self presentViewController:alertController animated:YES completion:nil];
             }else{
                 //self.myNickname.text = new.text;
                 NSLog(@"ADD FREQDriver SUCCESSFULLY!");
                 UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"添加成功" message:@"" preferredStyle:UIAlertControllerStyleAlert];
                 UIAlertAction *okAction = [UIAlertAction actionWithTitle:@"好的" style:UIAlertActionStyleDefault handler:^(UIAlertAction *action) {
                     SubDriverViewController *setsubDriverVC = [self.navigationController.viewControllers objectAtIndex:self.navigationController.viewControllers.count-3];
                     
                     setsubDriverVC.refreshStat = @"refresh";
                     //使用popToViewController返回并传值到上一页面
                     [self.navigationController popToViewController:setsubDriverVC animated:true];
                 }];
                 [alertController addAction:okAction];
                 [self presentViewController:alertController animated:YES completion:nil];
             }
         }];
    }
    //返回时取消选中
    [tableView deselectRowAtIndexPath:indexPath animated:NO];
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    
}

@end