#pragma once

#ifndef INFOS_H
#define INFOS_H

namespace Infos {
	struct OwnerInfo {
		char name[20];
		char phoneNumber[15];
		char email[30];
		char address[50];
		char twitterAccount[20];
	};

	struct  ContactInfo {
		char name[20];
		char phoneNumber[15];
		char email[30];
		char address[50];
	};
}

#endif // INFOS_H