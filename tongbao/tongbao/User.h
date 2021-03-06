//
//  User.h
//  tongbao
//
//  Created by 蒋秉洁 on 16/3/14.
//  Copyright © 2016年 ZX. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "Order.h"
#import "Address.h"
#import "Driver.h"
#import "Comment.h"
#import "confirmedOrder.h"
@interface User : NSObject

/**
 *  Single Instance of User
 *
 *  @return us
 */
+ (instancetype)currentUser;


/**
 *  username： in our case, it's 电话号码
 */

@property (copy, nonatomic, readonly) NSString *username;
@property (copy, nonatomic) NSString *nickname;

@property (copy, nonatomic) NSString *iconUrl;
@property (copy, nonatomic) NSString *point;
@property (copy, nonatomic) NSString *money;
@property (copy, nonatomic, readonly) NSString *token;
@property (strong, nonatomic) NSMutableArray *billList;

@property (strong, nonatomic) NSMutableArray *msgList;
@property (strong, nonatomic) NSMutableArray *freqAddrList;
@property (strong, nonatomic) NSMutableArray *freqDriverList;
@property (strong, nonatomic) NSMutableArray *driverList;
@property (strong, nonatomic) NSMutableArray *truckList;
@property (strong, nonatomic) NSMutableArray *orderList;
@property (strong, nonatomic) NSMutableArray *waitingOrderList;
@property (strong, nonatomic) NSMutableArray *deliveringOrderList;
@property (strong, nonatomic) NSMutableArray *finishedOrderList;
@property (strong, nonatomic) NSMutableArray *canceledOrderList;
@property (strong, nonatomic) NSMutableArray *driversPositionList;

/**
 *  Judge whether user has login
 *
 *  @return whether user has login
 */
+ (BOOL)hasLogin;


/**
 *  login method
 *
 *  @param stuId          stuID
 *  @param password       password
 *  @param completedBlock complete block
 */
+ (void)loginWithUsername:(NSString *)username andPassword:(NSString *)password withBlock:(void (^)(NSError *error, User *user))completedBlock;

/**
* register method
 
*
 
*/

+(void) registerwithUsername: (NSString *)username andPassoword: (NSString *) password withBlock:(void (^)(NSError *error, User *user))completedBlock;

+(void) modifyNickname: (NSString *)newName withBlock:(void (^)(NSError *error, User *user))completedBlock;
+(void) modifyPassword: (NSString *)newPwd withBlock:(void (^)(NSError *error, User *user))completedBlock;
+(void) uploadImage: (UIImage *)newHead withBlock:(void (^)(NSError *error, User *user))completedBlock;
+(void) modifyHeadportrait: (NSString *)newUrl withBlock:(void (^)(NSError *error, User *user))completedBlock;

+(void) withdrawMoney: (NSInteger) money withBlock:(void (^)(NSError *error, User *user))completedBlock;
+(void) rechargeMoney: (NSInteger) money withBlock:(void (^)(NSError *error, User *user))completedBlock;
+(void) showBills:(void (^)(NSError *error, User *user))completedBlock;
+(void) showCurrent:(void (^)(NSError *error, User *user))completedBlock;


+ (UIImage *) getImageFromURL:(NSString *)fileURL;




/**
 * functions add by ZX
 *
 */



+(void) getMyMessages:(void (^)(NSError *error, User *user))completedBlock;
+(void) getFrequentAddresses:(void (^)(NSError *error, User *user))completedBlock;
+(void) addFrequentAddress: (Address*) address withBlock:(void (^)(NSError *error, User *user))completedBlock;

+(void) placeOrder: (Order*) order withBlock:(void (^)(NSError *error, User *user))completedBlock;
+(void) splitOrder: (Order*) order withBlock:(void (^)(NSError *error, User *user))completedBlock;

+(void) searchDriver: (NSString *) phoneNum withBlock:(void (^)(NSError *error, User *user))completedBlock;
+(void) addFrequentDriver: (Driver*) driver withBlock:(void (^)(NSError *error, User *user))completedBlock;
+(void) getFrequentDrivers:(void (^)(NSError *error, User *user))completedBlock;
+(void) getAllTruckTypes:(void (^)(NSError *error, User *user))completedBlock;
+(void) getDriversPosition:(void (^)(NSError *error, User *user))completedBlock;

+(void) showMyOrderList: (NSString*) type withBlock:(void (^)(NSError *error, User *user))completedBlock;
+(void) getOrderDetail: (NSString*) orderId withBlock:(void (^)(NSError *error, confirmedOrder *cfOrderItm))completedBlock;
+(void) cancelOrder: (NSString*) orderId withBlock:(void (^)(NSError *error, User *user))completedBlock;
+(void) finishOrder: (NSString*) orderId withBlock:(void (^)(NSError *error, User *user))completedBlock;
+(void) deleteOrder: (NSString*) orderId withBlock:(void (^)(NSError *error, User *user))completedBlock;
+(void) evaluateOrder: (Comment*) comment withBlock:(void (^)(NSError *error, User *user))completedBlock;
+(void) deleteFrequentAddress: (NSString*) freqAddrId withBlock:(void (^)(NSError *error, User *user))completedBlock;
+(void) deleteFrequentDriver: (NSString*) freqDriverId withBlock:(void (^)(NSError *error, User *user))completedBlock;
@end