#pragma once
#include <string>
#include <fnd/List.h>
#include <fnd/IByteModel.h>
#include <nn/hac/define/meta.h>
#include <nn/hac/AccessControlInfo.h>
#include <nn/hac/AccessControlInfoDesc.h>

namespace nn
{
namespace hac
{
	class Meta :
		public fnd::IByteModel
	{
	public:
		Meta();
		Meta(const Meta& other);

		void operator=(const Meta& other);
		bool operator==(const Meta& other) const;
		bool operator!=(const Meta& other) const;

		// IByteModel
		void toBytes();
		void fromBytes(const byte_t* bytes, size_t len);
		const fnd::Vec<byte_t>& getBytes() const;

		// variables
		void clear();

		meta::InstructionType getInstructionType() const;
		void setInstructionType(meta::InstructionType type);

		meta::ProcAddrSpaceType getProcAddressSpaceType() const;
		void setProcAddressSpaceType(meta::ProcAddrSpaceType type);

		byte_t getMainThreadPriority() const;
		void setMainThreadPriority(byte_t priority);

		byte_t getMainThreadCpuId() const;
		void setMainThreadCpuId(byte_t cpu_id);

		uint32_t getVersion() const;
		void setVersion(uint32_t version);

		uint32_t getMainThreadStackSize() const;
		void setMainThreadStackSize(uint32_t size);

		const std::string& getName() const;
		void setName(const std::string& name);

		const std::string& getProductCode() const;
		void setProductCode(const std::string& product_code);

		const AccessControlInfo& getAci() const;
		void setAci(const AccessControlInfo& aci);

		const AccessControlInfoDesc& getAcid() const;
		void setAcid(const AccessControlInfoDesc& acid);
	private:
		const std::string kModuleName = "META";

		// raw binary
		fnd::Vec<byte_t> mRawBinary;

		// variables
		meta::InstructionType mInstructionType;
		meta::ProcAddrSpaceType mProcAddressSpaceType;
		byte_t mMainThreadPriority;
		byte_t mMainThreadCpuId;
		uint32_t mVersion;
		uint32_t mMainThreadStackSize;
		std::string mName;
		std::string mProductCode;
		AccessControlInfo mAci;
		AccessControlInfoDesc mAcid;
	};
}
}
